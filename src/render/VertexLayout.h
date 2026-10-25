#pragma once

#include <vector>

namespace app {
    struct VertexElement {
        unsigned int index;
        unsigned int size;
        unsigned int type;
        unsigned int offset;
    };

    struct VertexLayout {
        std::vector<VertexElement> elements;
        unsigned int stride;
    };
} // namespace app
