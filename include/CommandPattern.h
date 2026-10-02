#ifndef COMMAND_PATTERN_H
#define COMMAND_PATTERN_H

struct Command{
    virtual int Execute(const int& arg) const = 0;
};

struct SayHello : public Command{
    int Execute(const int& arg) const override;
};

struct SayBye : public Command{
    int Execute(const int& arg) const override;
};

int CommandPattern();

#endif