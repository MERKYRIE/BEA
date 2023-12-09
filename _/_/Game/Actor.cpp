#include "Actor.hpp"

namespace NBEA::NGame
{    
    void CActor::PUpdate()
    {
        for(std::reference_wrapper<CComponent>& LComponent : FComponents)
        {
            LComponent.get().PUpdate();
        }
    }
}