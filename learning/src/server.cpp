// STL
#include <iostream>
// GRPC
#include <grpcpp/grpcpp.h>
#include <protos/update.pb.h>
#include <protos/update.grpc.pb.h>

class ServerImpl : public psl_update::ProcessingService::Service{
    ::grpc::Status computeValues(::grpc::ServerContext* context, const ::psl_update::Point3* request, ::psl_update::Numeric* response){
        std::cout << "Function called !!!!!!\n";
        response->set_value(request->x() + request->y() + request->z());
        return grpc::Status::OK;
    }
};

int main(int argc, char const *argv[])
{
    // Create an instance of the server
    ServerImpl service;
    grpc::ServerBuilder builder;
    
    builder.AddListeningPort("0.0.0.0:9999",grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server>(builder.BuildAndStart())->Wait();

    return 0;
}
