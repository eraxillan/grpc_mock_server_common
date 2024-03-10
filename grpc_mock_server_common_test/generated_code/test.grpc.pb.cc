// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test/test.proto

#include "test.pb.h"
#include "test.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace routeguide {

static const char* RouteGuide_method_names[] = {
  "/routeguide.RouteGuide/GetFeature",
};

std::unique_ptr< RouteGuide::Stub> RouteGuide::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< RouteGuide::Stub> stub(new RouteGuide::Stub(channel, options));
  return stub;
}

RouteGuide::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetFeature_(RouteGuide_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status RouteGuide::Stub::GetFeature(::grpc::ClientContext* context, const ::routeguide::Point& request, ::routeguide::Feature* response) {
  return ::grpc::internal::BlockingUnaryCall< ::routeguide::Point, ::routeguide::Feature, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetFeature_, context, request, response);
}

void RouteGuide::Stub::async::GetFeature(::grpc::ClientContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::routeguide::Point, ::routeguide::Feature, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetFeature_, context, request, response, std::move(f));
}

void RouteGuide::Stub::async::GetFeature(::grpc::ClientContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetFeature_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::routeguide::Feature>* RouteGuide::Stub::PrepareAsyncGetFeatureRaw(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::routeguide::Feature, ::routeguide::Point, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetFeature_, context, request);
}

::grpc::ClientAsyncResponseReader< ::routeguide::Feature>* RouteGuide::Stub::AsyncGetFeatureRaw(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetFeatureRaw(context, request, cq);
  result->StartCall();
  return result;
}

RouteGuide::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RouteGuide_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RouteGuide::Service, ::routeguide::Point, ::routeguide::Feature, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RouteGuide::Service* service,
             ::grpc::ServerContext* ctx,
             const ::routeguide::Point* req,
             ::routeguide::Feature* resp) {
               return service->GetFeature(ctx, req, resp);
             }, this)));
}

RouteGuide::Service::~Service() {
}

::grpc::Status RouteGuide::Service::GetFeature(::grpc::ServerContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace routeguide

