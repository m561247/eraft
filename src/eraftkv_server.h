/**
 * @file eraftkv_server.h
 * @author ERaftGroup
 * @brief
 * @version 0.1
 * @date 2023-03-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ERAFTKV_SERVER_H_
#define ERAFTKV_SERVER_H_

#include <cstdint>
#include <string>
#include <memory>

#include "estatus.h"
#include "raft_server.h"
#include "eraftkv.grpc.pb.h"
#include "eraftkv.pb.h"
#include <grpcpp/grpcpp.h>

using eraftkv::ERaftKv;
using grpc::ServerContext;
using grpc::Status;

/**
 * @brief
 *
 */
struct ERaftKvServerOptions {
  std::string svr_version;
  std::string svr_addr;
  std::string kv_db_path;
  std::string log_db_path;

  int64_t tick_interval;
  int64_t request_timeout;
  int64_t election_timeout;

  int64_t response_timeout;

  int64_t ae_max_count;
  int64_t ae_max_size;

  int64_t snap_max_count;
  int64_t snap_max_size;

  int64_t grpc_max_recv_msg_size;
  int64_t grpc_max_send_msg_size;
};

class ERaftKvServer : public eraftkv::ERaftKv::Service {

public:
  /**
   * @brief Construct a new ERaftKvServer object
   *
   * @param config
   */
  ERaftKvServer(ERaftKvServerOptions config) {
    // this.options_ = config;
    // // init raft lib
    // RaftConfig raft_config;
    // raft_config.net_impl = new GRpcNetworkImpl();
    // raft_config.store_impl = new RocksDBStorageImpl();
    // raft_config.log_impl = new RocksDBLogStorageImpl();
    // raft_context_ = new RaftServer(raft_config);
  }

  ERaftKvServer() {

  }

  /**
   * @brief
   *
   * @param req
   * @param resp
   * @return grpc::Status
   */
  Status RequestVote(ServerContext* context,const eraftkv::RequestVoteReq* req, eraftkv::RequestVoteResp* resp);

  /**
   * @brief
   *
   * @param req
   * @param resp
   * @return grpc::Status
   */
  Status AppendEntries(ServerContext* context,const eraftkv::AppendEntriesReq* req, eraftkv::RequestVoteResp* resp);
  /**
   * @brief
   *
   * @param req
   * @param resp
   * @return grpc::Status
   */
  Status Snapshot(ServerContext* context,const eraftkv::SnapshotReq* req, eraftkv::SnapshotResp* resp);

  /**
   * @brief
   *
   * @param req
   * @param resp
   * @return grpc::Status
   */
  Status ProcessRWOperation(ServerContext* context,const eraftkv::ClientOperationReq*  req,
                                  eraftkv::ClientOperationResp* resp);

  /**
   * @brief
   *
   * @return grpc::Status
   */
  Status ClusterConfigChange(ServerContext* context,const eraftkv::ClusterConfigChangeReq*  req,
                                  eraftkv::ClusterConfigChangeResp* resp);
  /**
   * @brief
   *
   * @param interval
   * @return EStatus
   */
  EStatus InitTicker(int interval);

  /**
   * @brief
   *
   * @return EStatus
   */
  EStatus BuildAndRunRpcServer();

  /**
   * @brief
   *
   */
  ERaftKvServerOptions options_;

 private:
  /**
   * @brief
   *
   */
  RaftServer* raft_context_;

  /**
   * @brief
   *
   */
  PeriodicCaller* periodic_caller_;

};


#endif