#include "Actor.hpp"

namespace NBEA::NGame
{    
    void CActor::FUpdate()
    {
        for(std::reference_wrapper<CComponent>& LComponent : VComponents)
        {
            LComponent.get().FUpdate();
        }
    }
}