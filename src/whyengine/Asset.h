#ifndef WHYENGINE_ASSET_H
#define WHYENGINE_ASSET_H

#include <string>
#include <memory>

namespace whyengine
{
    struct Core;
    struct Assets;

    struct Asset
    {
        virtual ~Asset();
        virtual void onLoad();

        std::string getPath();
        std::shared_ptr<Core> getCore();

    private:
        friend struct whyengine::Assets;

        std::string path;
        std::weak_ptr<Core> core;
    };
}

#endif