#include <iostream>

class AbstractGate
{
protected:
    bool x, y;

public:
    void set(const bool& x, const bool& y)
    {
        this->x = x;
        this->y = y;
    }
    virtual bool operation() = 0;
};

class ANDGate : public AbstractGate
{
public:
    virtual bool operation() override
    {
        if(x || y)
        {
            return false;
        }
        else
            return true;
    }
};

class ORGate : public AbstractGate
{
public:
    virtual bool operation() override
    {
        if(x || y)
        {
            return true;
        }
        else if(x && y)
        {
            return true;
        }
        else
            return false;
    }
};

class XORGate : public AbstractGate
{
public:
    virtual bool operation() override
    {
        if(x && y)
        {
            return false;
        }
        else if(!x && !y)
        {
            return false;
        }
        else
            return true;
    }
};

int main()
{
    ANDGate andG;
    ORGate orG;
    XORGate xorG;

    andG.set(true, false);
    orG.set(true, false);
    xorG.set(true, false);
    std::cout.setf(std::ios::boolalpha);
    std::cout << andG.operation() << std::endl;
    std::cout << orG.operation() << std::endl;
    std::cout << xorG.operation() << std::endl;
}