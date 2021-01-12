#include "Asset.h"
#include "Exception.h"

#include <rend/rend.h>
#include <string>
#include <memory>

namespace whyengine
{
    struct Renderer;

    struct Model : public Asset
    {
        void onLoad();
    private:
        friend struct whyengine::Renderer;

        std::shared_ptr<rend::Mesh> mesh;
    };
}