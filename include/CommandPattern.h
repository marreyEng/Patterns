#ifndef COMMAND_PATTERN_H
#define COMMAND_PATTERN_H

struct Command{
    virtual int Execute() const = 0;
};

struct SayHello : public Command{
    int Execute() const override;
};

struct SayBye : public Command{
    int Execute() const override;
};

int CommandPattern();

#endif