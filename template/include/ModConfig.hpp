#pragma once
#include "UnityEngine/Color.hpp"
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,

    CONFIG_VALUE(ExampleBool, bool, "ExampleBool", true);
    CONFIG_VALUE(ExampleFloat, float, "ExampleFloat", 1.0f);
    CONFIG_VALUE(ExampleColor, UnityEngine::Color, "ExampleFloat", UnityEngine::Color(1.0f, 1.0f, 1.0f, 1.0f));

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(ExampleBool);
        CONFIG_INIT_VALUE(ExampleFloat);
        CONFIG_INIT_VALUE(ExampleColor);
    )
)