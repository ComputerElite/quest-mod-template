#include "Settings.hpp"

#include "UnityEngine/RectOffset.hpp"
#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/UI/Image.hpp"
#include "UnityEngine/UI/Toggle.hpp"
#include "UnityEngine/UI/Toggle_ToggleEvent.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/Events/UnityAction.hpp"
#include "UnityEngine/Events/UnityAction_1.hpp"
#include "HMUI/ScrollView.hpp"
#include "HMUI/ModalView.hpp"
#include "HMUI/Touchable.hpp"
#include "main.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/CustomTypes/Components/ExternalComponents.hpp"
#include "questui/shared/CustomTypes/Components/Backgroundable.hpp"
#include <stdlib.h>

using namespace QuestUI;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace UnityEngine::Events;
using namespace HMUI;


void DidActivate(ViewController* self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling){
    if(firstActivation) {
        self->get_gameObject()->AddComponent<Touchable*>();
        GameObject* container = BeatSaberUI::CreateScrollableSettingsContainer(self->get_transform());

        // Toggle with hover hint (hover hint applies to all UI elements)
        QuestUI::BeatSaberUI::AddHoverHint(AddConfigValueToggle(container->get_transform(), getModConfig().ExampleBool)->get_gameObject(), "An Example toggle");

        // Increment
        //                                                                                    Decimal Places, Steps, min , max
        AddConfigValueIncrementFloat(container->get_transform(), getModConfig().ExampleFloat, 1             , 0.1f , 0.0f, 1.0f);

        // Button
        BeatSaberUI::CreateUIButton(container->get_transform(), "You Button", 
            []() {
                //Your code here
            });


        //Color
        AddConfigValueColorPicker(container->get_transform(), getModConfig().ExampleColor);

        // Text
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "Text");
    }
}