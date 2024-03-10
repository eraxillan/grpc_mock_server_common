// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test/test.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_test_2ftest_2eproto__INCLUDED
#define GRPC_test_2ftest_2eproto__INCLUDED

#include "test.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace routeguide {

// Interface exported by the server.
class RouteGuide final {
 public:
  static constexpr char const* service_full_name() {
    return "routeguide.RouteGuide";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // A simple RPC.
    //
    // Obtains the feature at a given position.
    //
    // A feature with an empty name is returned if there's no feature at the given
    // position.
    virtual ::grpc::Status GetFeature(::grpc::ClientContext* context, const ::routeguide::Point& request, ::routeguide::Feature* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routeguide::Feature>> AsyncGetFeature(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routeguide::Feature>>(AsyncGetFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routeguide::Feature>> PrepareAsyncGetFeature(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::routeguide::Feature>>(PrepareAsyncGetFeatureRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // A simple RPC.
      //
      // Obtains the feature at a given position.
      //
      // A feature with an empty name is returned if there's no feature at the given
      // position.
      virtual void GetFeature(::grpc::ClientContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GetFeature(::grpc::ClientContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::routeguide::Feature>* AsyncGetFeatureRaw(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::routeguide::Feature>* PrepareAsyncGetFeatureRaw(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status GetFeature(::grpc::ClientContext* context, const ::routeguide::Point& request, ::routeguide::Feature* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routeguide::Feature>> AsyncGetFeature(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routeguide::Feature>>(AsyncGetFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routeguide::Feature>> PrepareAsyncGetFeature(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::routeguide::Feature>>(PrepareAsyncGetFeatureRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void GetFeature(::grpc::ClientContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response, std::function<void(::grpc::Status)>) override;
      void GetFeature(::grpc::ClientContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::routeguide::Feature>* AsyncGetFeatureRaw(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::routeguide::Feature>* PrepareAsyncGetFeatureRaw(::grpc::ClientContext* context, const ::routeguide::Point& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetFeature_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // A simple RPC.
    //
    // Obtains the feature at a given position.
    //
    // A feature with an empty name is returned if there's no feature at the given
    // position.
    virtual ::grpc::Status GetFeature(::grpc::ServerContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetFeature() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::routeguide::Point* /*request*/, ::routeguide::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetFeature(::grpc::ServerContext* context, ::routeguide::Point* request, ::grpc::ServerAsyncResponseWriter< ::routeguide::Feature>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetFeature<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetFeature() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::routeguide::Point, ::routeguide::Feature>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::routeguide::Point* request, ::routeguide::Feature* response) { return this->GetFeature(context, request, response); }));}
    void SetMessageAllocatorFor_GetFeature(
        ::grpc::MessageAllocator< ::routeguide::Point, ::routeguide::Feature>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::routeguide::Point, ::routeguide::Feature>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::routeguide::Point* /*request*/, ::routeguide::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::routeguide::Point* /*request*/, ::routeguide::Feature* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_GetFeature<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetFeature() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::routeguide::Point* /*request*/, ::routeguide::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetFeature() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::routeguide::Point* /*request*/, ::routeguide::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetFeature(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetFeature() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetFeature(context, request, response); }));
    }
    ~WithRawCallbackMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::routeguide::Point* /*request*/, ::routeguide::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetFeature() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::routeguide::Point, ::routeguide::Feature>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::routeguide::Point, ::routeguide::Feature>* streamer) {
                       return this->StreamedGetFeature(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::routeguide::Point* /*request*/, ::routeguide::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetFeature(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::routeguide::Point,::routeguide::Feature>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GetFeature<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_GetFeature<Service > StreamedService;
};

}  // namespace routeguide


#endif  // GRPC_test_2ftest_2eproto__INCLUDED
