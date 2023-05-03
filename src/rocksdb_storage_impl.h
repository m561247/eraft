/**
 * @file rocksdb_storage_impl.h
 * @author ERaftGroup
 * @brief
 * @version 0.1
 * @date 2023-03-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ROCKSDB_STORAGE_IMPL_H_
#define ROCKSDB_STORAGE_IMPL_H_


#include <rocksdb/db.h>

#include "log_entry_cache.h"
#include "raft_server.h"

/**
 * @brief
 *
 */
class RocksDBStorageImpl : public Storage {

 public:
  /**
   * @brief Get the Node Address object
   *
   * @param raft
   * @param id
   * @return std::string
   */
  std::string GetNodeAddress(RaftServer* raft, std::string id);

  /**
   * @brief
   *
   * @param raft
   * @param id
   * @param address
   * @return absl::Status
   */
  absl::Status SaveNodeAddress(RaftServer* raft,
                          std::string id,
                          std::string address);

  /**
   * @brief
   *
   * @param raft
   * @param snapshot_index
   * @param snapshot_term
   * @return absl::Status
   */
  absl::Status ApplyLog(RaftServer* raft,
                   int64_t     snapshot_index,
                   int64_t     snapshot_term);

  /**
   * @brief Get the Snapshot Block object
   *
   * @param raft
   * @param node
   * @param offset
   * @param block
   * @return absl::Status
   */
  absl::Status GetSnapshotBlock(RaftServer*             raft,
                           RaftNode*               node,
                           int64_t                 offset,
                           eraftkv::SnapshotBlock* block);

  /**
   * @brief
   *
   * @param raft
   * @param snapshot_index
   * @param offset
   * @param block
   * @return absl::Status
   */
  absl::Status StoreSnapshotBlock(RaftServer*             raft,
                             int64_t                 snapshot_index,
                             int64_t                 offset,
                             eraftkv::SnapshotBlock* block);

  /**
   * @brief
   *
   * @param raft
   * @return absl::Status
   */
  absl::Status ClearSnapshot(RaftServer* raft);

  /**
   * @brief
   *
   * @return absl::Status
   */
  absl::Status CreateDBSnapshot();

  /**
   * @brief
   *
   * @param raft
   * @param term
   * @param vote
   * @return absl::Status
   */
  absl::Status SaveRaftMeta(RaftServer* raft, int64_t term, int64_t vote);

  /**
   * @brief
   *
   * @param raft
   * @param term
   * @param vote
   * @return absl::Status
   */
  absl::Status ReadRaftMeta(RaftServer* raft, int64_t* term, int64_t* vote);


  /**
   * @brief
   *
   * @param key
   * @param val
   * @return absl::Status
   */
  absl::Status PutKV(std::string key, std::string val);

  /**
   * @brief
   *
   * @param key
   * @return std::string
   */
  std::string GetKV(std::string key);

  /**
   * @brief Construct a new RocksDB Storage Impl object
   *
   * @param db_path
   */
  RocksDBStorageImpl(std::string db_path);

  /**
   * @brief Destroy the Rocks DB Storage Impl object
   *
   */
  ~RocksDBStorageImpl();

 private:
  /**
   * @brief
   *
   */
  std::string db_path_;

  /**
   * @brief
   *
   */
  rocksdb::DB* kv_db_;
};


struct LogDBStatus {
  int64_t     prev_log_term;
  int64_t     prev_log_index;
  int64_t     entries_count;
  int64_t     last_log_index;
  std::string db_path;
  int64_t     db_size;
};


/**
 * @brief
 *
 */
class RocksDBLogStorageImpl : public LogStore {

 public:
  /**
   * @brief
   *
   */
  RocksDBLogStorageImpl();

  /**
   * @brief
   *
   */
  ~RocksDBLogStorageImpl();


  absl::Status Reset(int64_t index, int64_t term);

  absl::Status Open(std::string logdb_path,
               int64_t     pre_log_term,
               int64_t     pre_log_index);

  /**
   * @brief
   *
   * @param ety
   * @return absl::Status
   */
  absl::Status Append(eraftkv::Entry* ety);

  /**
   * @brief
   *
   * @param first_index
   * @return absl::Status
   */
  absl::Status EraseBefore(int64_t first_index);

  /**
   * @brief
   *
   * @param from_index
   * @return absl::Status
   */
  absl::Status EraseAfter(int64_t from_index);

  /**
   * @brief
   *
   * @param index
   * @return eraftkv::Entry*
   */
  eraftkv::Entry* Get(int64_t index);

  /**
   * @brief
   *
   * @param start_index
   * @param end_index
   * @return std::vector<eraftkv::Entry*>
   */
  std::vector<eraftkv::Entry*> Gets(int64_t start_index, int64_t end_index);

  /**
   * @brief
   *
   * @return int64_t
   */
  int64_t FirstIndex();

  /**
   * @brief
   *
   * @return int64_t
   */
  int64_t LastIndex();

  /**
   * @brief
   *
   * @return int64_t
   */
  int64_t LogCount();

 private:
  /**
   * @brief
   *
   */
  uint64_t count_;
  /**
   * @brief
   *
   */
  std::string node_id_;

  /**
   * @brief
   *
   */
  rocksdb::DB* master_log_db_;

  /**
   * @brief
   *
   */
  LogDBStatus m_status_;

  /**
   * @brief
   *
   */
  rocksdb::DB* standby_log_db_;

  /**
   * @brief
   *
   */
  LogDBStatus s_status_;

  /**
   * @brief cache for log entry
   *
   */
  LogEntryCache* log_cache_;
};

#endif
