#pragma once

enum class EJob {
    ART,
    MILITARY,
    POLITICS,
    REST
};

// Interface
class IJob {
public:
    virtual EJob GetJobName () = 0;
    virtual void DoJob () = 0;
};

class CArtEducation : public IJob {
public:
    EJob GetJobName () { return EJob::ART; }
    void DoJob () {}
};


class CMilitaryEducation : public IJob {
public:
    EJob GetJobName () { return EJob::MILITARY; }
    void DoJob () {}
};

class CPoliticsEducation : public IJob {
public:
    EJob GetJobName () { return EJob::POLITICS; }
    void DoJob () {}
};

class CRest : public IJob {
public:
    EJob GetJobName () { return EJob::REST; }
    void DoJob () {}
};
