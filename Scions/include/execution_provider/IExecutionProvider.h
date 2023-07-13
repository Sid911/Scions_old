//
// Created by sid on 12/7/23.
//

#ifndef SCIONS_IEXECUTIONPROVIDER_H
#define SCIONS_IEXECUTIONPROVIDER_H

#pragma once

#include "common/common.h"

namespace sc::ep {

    class IExecutionProvider {
    public:
        virtual ~IExecutionProvider();

        // Initialize the execution provider, e.g. load backend library, create contexts, etc.
        [[nodiscard]] virtual sc::result::Result<std::uint32_t, std::string> Initialize() = 0;

/*        // Compile a node
        virtual sc::Status Compile(const std::vector<NodeComputeInfo> &node_compute_funcs) = 0;

        // Execute the node
        virtual sc::Status Execute(const std::vector <NodeComputeInfo> &node_compute_funcs,
                                   const common::ThreadPool::TrySubmit &try_submit) = 0;
*/
    };

}
#endif //SCIONS_IEXECUTIONPROVIDER_H
