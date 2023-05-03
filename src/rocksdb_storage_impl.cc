/**
 * @file rocksdb_storage_impl.cc
 * @author ERaftGroup
 * @brief
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "rocksdb_storage_impl.h"

/**
 * @brief Get the Node Address object
 *
 * @param raft
 * @param id
 * @return std::string
 */
std::string RocksDBStorageImpl::GetNodeAddress(RaftServer* raft,
                                               std::string id) {
  return std::string("");
}

/**
 * @brief
 *
 * @param raft
 * @param id
 * @param address
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::SaveNodeAddress(RaftServer* raft,
                                            std::string id,
                                            std::string address) {
  return absl::OkStatus();
}

/**
 * @brief
 *
 * @param raft
 * @param snapshot_index
 * @param snapshot_term
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::ApplyLog(RaftServer* raft,
                                     int64_t     snapshot_index,
                                     int64_t     snapshot_term) {
  return absl::OkStatus();
}

/**
 * @brief Get the Snapshot Block object
 *
 * @param raft
 * @param node
 * @param offset
 * @param block
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::GetSnapshotBlock(RaftServer*             raft,
                                             RaftNode*               node,
                                             int64_t                 offset,
                                             eraftkv::SnapshotBlock* block) {
  return absl::OkStatus();
}

/**
 * @brief
 *
 * @param raft
 * @param snapshot_index
 * @param offset
 * @param block
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::StoreSnapshotBlock(RaftServer* raft,
                                               int64_t     snapshot_index,
                                               int64_t     offset,
                                               eraftkv::SnapshotBlock* block) {
  return absl::OkStatus();
}

/**
 * @brief
 *
 * @param raft
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::ClearSnapshot(RaftServer* raft) {
  return absl::OkStatus();
}

/**
 * @brief
 *
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::CreateDBSnapshot() {
  return absl::OkStatus();
}

/**
 * @brief
 *
 * @param raft
 * @param term
 * @param vote
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::SaveRaftMeta(RaftServer* raft,
                                         int64_t     term,
                                         int64_t     vote) {
  return absl::OkStatus();
}

/**
 * @brief
 *
 * @param raft
 * @param term
 * @param vote
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::ReadRaftMeta(RaftServer* raft,
                                         int64_t*    term,
                                         int64_t*    vote) {

  return absl::OkStatus();
}


/**
 * @brief put key and value to kv rocksdb
 *
 * @param key
 * @param val
 * @return absl::Status
 */
absl::Status RocksDBStorageImpl::PutKV(std::string key, std::string val) {
  auto status = kv_db_->Put(rocksdb::WriteOptions(), key, val);
  return status.ok() ? absl::OkStatus() : absl::Status(absl::StatusCode::kPutKeyToRocksDBErr, "");
}

/**
 * @brief get value from kv rocksdb
 *
 * @param key
 * @return std::string
 */
std::string RocksDBStorageImpl::GetKV(std::string key) {
  std::string value;
  auto        status = kv_db_->Get(rocksdb::ReadOptions(), key, &value);
  return status.IsNotFound() ? "" : value;
}

/**
 * @brief Construct a new RocksDB Storage Impl object
 *
 * @param db_path
 */
RocksDBStorageImpl::RocksDBStorageImpl(std::string db_path) {
  rocksdb::Options options;
  options.create_if_missing = true;
  rocksdb::Status status = rocksdb::DB::Open(options, db_path, &kv_db_);
  assert(status.ok());
}

/**
 * @brief Destroy the Rocks D B Storage Impl:: RocksDB Storage Impl object
 *
 */
RocksDBStorageImpl::~RocksDBStorageImpl() {
  delete kv_db_;
}
