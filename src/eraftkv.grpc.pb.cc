// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: eraftkv.proto

#include "eraftkv.pb.h"
#include "eraftkv.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace eraftkv {

static const char* ERaftKv_method_names[] = {
  "/eraftkv.ERaftKv/RequestVote",
  "/eraftkv.ERaftKv/AppendEntries",
  "/eraftkv.ERaftKv/Snapshot",
  "/eraftkv.ERaftKv/PutSSTFile",
  "/eraftkv.ERaftKv/ProcessRWOperation",
  "/eraftkv.ERaftKv/ClusterConfigChange",
};

std::unique_ptr< ERaftKv::Stub> ERaftKv::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ERaftKv::Stub> stub(new ERaftKv::Stub(channel));
  return stub;
}

ERaftKv::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_RequestVote_(ERaftKv_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AppendEntries_(ERaftKv_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Snapshot_(ERaftKv_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_PutSSTFile_(ERaftKv_method_names[3], ::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_ProcessRWOperation_(ERaftKv_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ClusterConfigChange_(ERaftKv_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ERaftKv::Stub::RequestVote(::grpc::ClientContext* context, const ::eraftkv::RequestVoteReq& request, ::eraftkv::RequestVoteResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_RequestVote_, context, request, response);
}

void ERaftKv::Stub::experimental_async::RequestVote(::grpc::ClientContext* context, const ::eraftkv::RequestVoteReq* request, ::eraftkv::RequestVoteResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RequestVote_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::RequestVote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::RequestVoteResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RequestVote_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::RequestVote(::grpc::ClientContext* context, const ::eraftkv::RequestVoteReq* request, ::eraftkv::RequestVoteResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_RequestVote_, context, request, response, reactor);
}

void ERaftKv::Stub::experimental_async::RequestVote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::RequestVoteResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_RequestVote_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::RequestVoteResp>* ERaftKv::Stub::AsyncRequestVoteRaw(::grpc::ClientContext* context, const ::eraftkv::RequestVoteReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::RequestVoteResp>::Create(channel_.get(), cq, rpcmethod_RequestVote_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::RequestVoteResp>* ERaftKv::Stub::PrepareAsyncRequestVoteRaw(::grpc::ClientContext* context, const ::eraftkv::RequestVoteReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::RequestVoteResp>::Create(channel_.get(), cq, rpcmethod_RequestVote_, context, request, false);
}

::grpc::Status ERaftKv::Stub::AppendEntries(::grpc::ClientContext* context, const ::eraftkv::AppendEntriesReq& request, ::eraftkv::AppendEntriesResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_AppendEntries_, context, request, response);
}

void ERaftKv::Stub::experimental_async::AppendEntries(::grpc::ClientContext* context, const ::eraftkv::AppendEntriesReq* request, ::eraftkv::AppendEntriesResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_AppendEntries_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::AppendEntries(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::AppendEntriesResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_AppendEntries_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::AppendEntries(::grpc::ClientContext* context, const ::eraftkv::AppendEntriesReq* request, ::eraftkv::AppendEntriesResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_AppendEntries_, context, request, response, reactor);
}

void ERaftKv::Stub::experimental_async::AppendEntries(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::AppendEntriesResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_AppendEntries_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::AppendEntriesResp>* ERaftKv::Stub::AsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::eraftkv::AppendEntriesReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::AppendEntriesResp>::Create(channel_.get(), cq, rpcmethod_AppendEntries_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::AppendEntriesResp>* ERaftKv::Stub::PrepareAsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::eraftkv::AppendEntriesReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::AppendEntriesResp>::Create(channel_.get(), cq, rpcmethod_AppendEntries_, context, request, false);
}

::grpc::Status ERaftKv::Stub::Snapshot(::grpc::ClientContext* context, const ::eraftkv::SnapshotReq& request, ::eraftkv::SnapshotResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Snapshot_, context, request, response);
}

void ERaftKv::Stub::experimental_async::Snapshot(::grpc::ClientContext* context, const ::eraftkv::SnapshotReq* request, ::eraftkv::SnapshotResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Snapshot_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::Snapshot(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::SnapshotResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Snapshot_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::Snapshot(::grpc::ClientContext* context, const ::eraftkv::SnapshotReq* request, ::eraftkv::SnapshotResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Snapshot_, context, request, response, reactor);
}

void ERaftKv::Stub::experimental_async::Snapshot(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::SnapshotResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Snapshot_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::SnapshotResp>* ERaftKv::Stub::AsyncSnapshotRaw(::grpc::ClientContext* context, const ::eraftkv::SnapshotReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::SnapshotResp>::Create(channel_.get(), cq, rpcmethod_Snapshot_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::SnapshotResp>* ERaftKv::Stub::PrepareAsyncSnapshotRaw(::grpc::ClientContext* context, const ::eraftkv::SnapshotReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::SnapshotResp>::Create(channel_.get(), cq, rpcmethod_Snapshot_, context, request, false);
}

::grpc::ClientWriter< ::eraftkv::SSTFileContent>* ERaftKv::Stub::PutSSTFileRaw(::grpc::ClientContext* context, ::eraftkv::SSTFileId* response) {
  return ::grpc_impl::internal::ClientWriterFactory< ::eraftkv::SSTFileContent>::Create(channel_.get(), rpcmethod_PutSSTFile_, context, response);
}

void ERaftKv::Stub::experimental_async::PutSSTFile(::grpc::ClientContext* context, ::eraftkv::SSTFileId* response, ::grpc::experimental::ClientWriteReactor< ::eraftkv::SSTFileContent>* reactor) {
  ::grpc_impl::internal::ClientCallbackWriterFactory< ::eraftkv::SSTFileContent>::Create(stub_->channel_.get(), stub_->rpcmethod_PutSSTFile_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::eraftkv::SSTFileContent>* ERaftKv::Stub::AsyncPutSSTFileRaw(::grpc::ClientContext* context, ::eraftkv::SSTFileId* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc_impl::internal::ClientAsyncWriterFactory< ::eraftkv::SSTFileContent>::Create(channel_.get(), cq, rpcmethod_PutSSTFile_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::eraftkv::SSTFileContent>* ERaftKv::Stub::PrepareAsyncPutSSTFileRaw(::grpc::ClientContext* context, ::eraftkv::SSTFileId* response, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncWriterFactory< ::eraftkv::SSTFileContent>::Create(channel_.get(), cq, rpcmethod_PutSSTFile_, context, response, false, nullptr);
}

::grpc::Status ERaftKv::Stub::ProcessRWOperation(::grpc::ClientContext* context, const ::eraftkv::ClientOperationReq& request, ::eraftkv::ClientOperationResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_ProcessRWOperation_, context, request, response);
}

void ERaftKv::Stub::experimental_async::ProcessRWOperation(::grpc::ClientContext* context, const ::eraftkv::ClientOperationReq* request, ::eraftkv::ClientOperationResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ProcessRWOperation_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::ProcessRWOperation(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::ClientOperationResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ProcessRWOperation_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::ProcessRWOperation(::grpc::ClientContext* context, const ::eraftkv::ClientOperationReq* request, ::eraftkv::ClientOperationResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ProcessRWOperation_, context, request, response, reactor);
}

void ERaftKv::Stub::experimental_async::ProcessRWOperation(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::ClientOperationResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ProcessRWOperation_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::ClientOperationResp>* ERaftKv::Stub::AsyncProcessRWOperationRaw(::grpc::ClientContext* context, const ::eraftkv::ClientOperationReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::ClientOperationResp>::Create(channel_.get(), cq, rpcmethod_ProcessRWOperation_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::ClientOperationResp>* ERaftKv::Stub::PrepareAsyncProcessRWOperationRaw(::grpc::ClientContext* context, const ::eraftkv::ClientOperationReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::ClientOperationResp>::Create(channel_.get(), cq, rpcmethod_ProcessRWOperation_, context, request, false);
}

::grpc::Status ERaftKv::Stub::ClusterConfigChange(::grpc::ClientContext* context, const ::eraftkv::ClusterConfigChangeReq& request, ::eraftkv::ClusterConfigChangeResp* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_ClusterConfigChange_, context, request, response);
}

void ERaftKv::Stub::experimental_async::ClusterConfigChange(::grpc::ClientContext* context, const ::eraftkv::ClusterConfigChangeReq* request, ::eraftkv::ClusterConfigChangeResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ClusterConfigChange_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::ClusterConfigChange(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::ClusterConfigChangeResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_ClusterConfigChange_, context, request, response, std::move(f));
}

void ERaftKv::Stub::experimental_async::ClusterConfigChange(::grpc::ClientContext* context, const ::eraftkv::ClusterConfigChangeReq* request, ::eraftkv::ClusterConfigChangeResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ClusterConfigChange_, context, request, response, reactor);
}

void ERaftKv::Stub::experimental_async::ClusterConfigChange(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::eraftkv::ClusterConfigChangeResp* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_ClusterConfigChange_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::ClusterConfigChangeResp>* ERaftKv::Stub::AsyncClusterConfigChangeRaw(::grpc::ClientContext* context, const ::eraftkv::ClusterConfigChangeReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::ClusterConfigChangeResp>::Create(channel_.get(), cq, rpcmethod_ClusterConfigChange_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::eraftkv::ClusterConfigChangeResp>* ERaftKv::Stub::PrepareAsyncClusterConfigChangeRaw(::grpc::ClientContext* context, const ::eraftkv::ClusterConfigChangeReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::eraftkv::ClusterConfigChangeResp>::Create(channel_.get(), cq, rpcmethod_ClusterConfigChange_, context, request, false);
}

ERaftKv::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ERaftKv_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ERaftKv::Service, ::eraftkv::RequestVoteReq, ::eraftkv::RequestVoteResp>(
          std::mem_fn(&ERaftKv::Service::RequestVote), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ERaftKv_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ERaftKv::Service, ::eraftkv::AppendEntriesReq, ::eraftkv::AppendEntriesResp>(
          std::mem_fn(&ERaftKv::Service::AppendEntries), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ERaftKv_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ERaftKv::Service, ::eraftkv::SnapshotReq, ::eraftkv::SnapshotResp>(
          std::mem_fn(&ERaftKv::Service::Snapshot), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ERaftKv_method_names[3],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< ERaftKv::Service, ::eraftkv::SSTFileContent, ::eraftkv::SSTFileId>(
          std::mem_fn(&ERaftKv::Service::PutSSTFile), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ERaftKv_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ERaftKv::Service, ::eraftkv::ClientOperationReq, ::eraftkv::ClientOperationResp>(
          std::mem_fn(&ERaftKv::Service::ProcessRWOperation), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ERaftKv_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ERaftKv::Service, ::eraftkv::ClusterConfigChangeReq, ::eraftkv::ClusterConfigChangeResp>(
          std::mem_fn(&ERaftKv::Service::ClusterConfigChange), this)));
}

ERaftKv::Service::~Service() {
}

::grpc::Status ERaftKv::Service::RequestVote(::grpc::ServerContext* context, const ::eraftkv::RequestVoteReq* request, ::eraftkv::RequestVoteResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ERaftKv::Service::AppendEntries(::grpc::ServerContext* context, const ::eraftkv::AppendEntriesReq* request, ::eraftkv::AppendEntriesResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ERaftKv::Service::Snapshot(::grpc::ServerContext* context, const ::eraftkv::SnapshotReq* request, ::eraftkv::SnapshotResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ERaftKv::Service::PutSSTFile(::grpc::ServerContext* context, ::grpc::ServerReader< ::eraftkv::SSTFileContent>* reader, ::eraftkv::SSTFileId* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ERaftKv::Service::ProcessRWOperation(::grpc::ServerContext* context, const ::eraftkv::ClientOperationReq* request, ::eraftkv::ClientOperationResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ERaftKv::Service::ClusterConfigChange(::grpc::ServerContext* context, const ::eraftkv::ClusterConfigChangeReq* request, ::eraftkv::ClusterConfigChangeResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace eraftkv
