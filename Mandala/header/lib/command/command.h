#ifndef COMMAND
#define COMMAND

struct Command {
    virtual void execute() = 0;
    virtual void cancel () = 0;
};

#endif // COMMAND
