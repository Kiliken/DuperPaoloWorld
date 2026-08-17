// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/GameController.h"
#include "imgui.h"
#include "ImGuiModule.h"
#include "DuperPaoloWorldCharacter.h"
#include "utils/PUtils.h"

// Sets default values
AGameController::AGameController()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    this->Tags.AddUnique(TEXT("Controller"));
}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
    Super::BeginPlay();

    PC = GetWorld()->GetFirstPlayerController();
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if(charController == nullptr){
        charController = Cast<ADuperPaoloWorldCharacter>(PUTILS::GetFirstActorByTag("Player",this->GetWorld()));

        if(charController == nullptr)
		    return;
    }

    if (PC->IsInputKeyDown(EKeys::LeftShift) && playerSt > 1.f)
    {
        //charController->SetRunningState(true);
        playerSt -= 10.f * DeltaTime;
    }
    else if(playerSt < 100.f){
        //charController->SetRunningState(false);
        playerSt += 10.f * DeltaTime;
    }

    ShowStatBarUI();
    ShowScoreUI();
}

void AGameController::ShowScoreUI()
{
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", score);

    ImGuiIO &io = ImGui::GetIO();
    // Calculate center of the screen
    ImVec2 center = ImVec2(io.DisplaySize.x * 0.05f, io.DisplaySize.y * 0.05f);

    // Set next window position to center, with pivot at the center
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Optionally set fixed size (so user can’t resize)
    ImGui::SetNextWindowSize(ImVec2(150.0f, 60.0f), ImGuiCond_Always);

    // Window flags: no resize, no move, no collapse, no title bar (optional)
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings;

    // Set Style
    ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));

    ImGui::Begin("SCORE", nullptr, flags);

    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth = 100.0f;

    ImGui::SetWindowFontScale(1.3f);

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text("%s", buffer, ImVec2(textWidth, 0));

    ImGui::End();

    // Restore colors
    ImGui::PopStyleColor(1);
}

void AGameController::ShowStatBarUI()
{
    char HPbuffer[32];
    snprintf(HPbuffer, sizeof(HPbuffer), "%.0f/100", playerHp);
    char STbuffer[32];
    snprintf(STbuffer, sizeof(STbuffer), "%.0f/100", playerSt);

    float HPprogress = playerHp / 100.f;
    float STprogress = playerSt / 100.f;

    ImGuiIO &io = ImGui::GetIO();
    // Calculate center of the screen
    ImVec2 center = ImVec2(io.DisplaySize.x * 0.01f, io.DisplaySize.y * 0.01f);

    // Set next window position to center, with pivot at the center
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.0f, 0.0f));

    // Optionally set fixed size (so user can’t resize)
    ImGui::SetNextWindowSize(ImVec2(450.0f, 120.0f), ImGuiCond_Always);

    // Window flags: no resize, no move, no collapse, no title bar (optional)
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings;

    // Set Style
    ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));

    ImGui::Begin("PLAYER STATS", nullptr, flags);

    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth = 100.0f;

    ImGui::SetWindowFontScale(1.3f);

    // ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.1f, 0.8f, 0.3f, 1.0f));
    ImGui::ProgressBar(HPprogress, ImVec2(-1.0f, 0.0f), HPbuffer);
    ImGui::PopStyleColor(1);

    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.0f, 0.5f, 1.0f, 1.0f));
    ImGui::ProgressBar(STprogress, ImVec2(-1.0f, 0.0f), STbuffer);
    ImGui::PopStyleColor(1);

    ImGui::End();

    // Restore colors
    ImGui::PopStyleColor(2);
}
