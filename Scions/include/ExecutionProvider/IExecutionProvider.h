//
// Created by sid on 12/7/23.
//

#ifndef SCIONS_IEXECUTIONPROVIDER_H
#define SCIONS_IEXECUTIONPROVIDER_H

namespace sc::EP {
    class IExecutionProvider {
    public:
        IExecutionProvider();

        virtual void initialize();
    };

}

#endif //SCIONS_IEXECUTIONPROVIDER_H
