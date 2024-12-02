#ifndef INDEXSTATUS_H
#define INDEXSTATUS_H

enum class indexStatus {
    INDEXING,
    READY,
    STOPPED,
    PAUSED,
    QUERYING,
    RESULT_AVAILABLE
};

const char* statusToString(indexStatus status);

#endif // INDEXSTATUS_H
