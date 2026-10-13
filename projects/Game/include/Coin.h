#pragma once

#include <UniDx.h>


class Coin : public UniDx::Behaviour
{
public:
    virtual void Start() override;
    virtual void Update() override;
};

