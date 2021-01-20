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
using namespace #{id};

DEFINE_CLASS(#{id}ViewController);

void SetBool(#{id}ViewController* self, bool newValue) {
    getConfig().config["Property"].SetBool(newValue);
}

void SetFloat(#{id}ViewController* self, float newValue)   {
    getConfig().config["Property"].SetFloat(newValue);
}

void ButtonPress(#{id}ViewController* self)  {
    // Do something
}


void #{id}ViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling){
    if(firstActivation) {
        get_gameObject()->AddComponent<Touchable*>();
        GameObject* container = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        // Toggle
        auto TogglePress = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<bool>*>(
                   classof(UnityEngine::Events::UnityAction_1<bool>*), this, SetBool);
        UnityEngine::UI::Toggle* ToggleObject = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Toggle Text", getConfig().config["Property"].GetBool(), TogglePress);
        QuestUI::BeatSaberUI::AddHoverHint(ToggleObject->get_gameObject(), "Hover Hint for Toggle");

        // Increment
        auto IncrementChange = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction_1<float>*>(
                    classof(UnityEngine::Events::UnityAction_1<float>*), this, SetFloat);
                    //                                                                                                                          Decimal places   Value Steps                                            Min Value   Max Value
        QuestUI::IncrementSetting* IncrementObject = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Increment Text", 0              , 1.0        , getConfig().config["Property"].GetFloat(), 0.0f      , 100.0f  , IncrementChange);
        QuestUI::BeatSaberUI::AddHoverHint(IncrementObject->get_gameObject(), "Hover Hint for Increment");

        // Button
        auto ButtonPressed = il2cpp_utils::MakeDelegate<UnityEngine::Events::UnityAction*>(
                    classof(UnityEngine::Events::UnityAction*), this, ButtonPress);
        UnityEngine::UI::Button* ButtonObject = QuestUI::BeatSaberUI::CreateUIButton(container->get_transform(), "Button Text", ButtonPressed);
        QuestUI::BeatSaberUI::AddHoverHint(ButtonObject->get_gameObject(), "Hover Hint for Button");

        // Text
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "Text");
    }
}

void #{id}ViewController::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling) {
    getConfig().Write();
}