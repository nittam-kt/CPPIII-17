#pragma once

#include <functional>
#include <algorithm>


template<typename T>
class Tweener
{
public:
    using Setter = std::function<void(const T&)>;

    Tweener(
        const T& startValue,
        const T& endValue,
        float duration,
        Setter setter)
        : start_(startValue)
        , end_(endValue)
        , duration_(std::max(duration, 0.0f))
        , setter_(std::move(setter))
    {
    }

    void Update(float deltaTime)
    {
        if(IsFinished()) return;

        elapsed_ += deltaTime;

        // 0 ` 1 ‚ÌŽžŠÔ
        float normalizedTime = std::clamp(elapsed_ / duration_, 0.0f, 1.0f);

        // ƒpƒ‰ƒ[ƒ^‚É—^‚¦‚éŽžŠÔiEase‘Î‰ž‚·‚éê‡‚Í‚±‚±‚ðŒvŽZ‚·‚éj
        float tweenTime = normalizedTime;

        T value = start_ + (end_ - start_) * tweenTime;
        setter_(value);
    }

    bool IsFinished() const
    {
        return elapsed_ >= duration_;
    }

private:
    T start_;
    T end_;
    T current_;

    float duration_;
    float elapsed_ = 0.0f;

    Setter setter_;
};
