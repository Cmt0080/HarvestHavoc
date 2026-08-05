// Fill out your copyright notice in the Description page of Project Settings.

#include "PlantPlot.h"
#include "TimerManager.h"
#include "CropData.h"

APlantPlot::APlantPlot()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APlantPlot::Interact()
{
	switch (CurrentState)
	{
	case EPlotState::Empty:
		{
			SetState(EPlotState::Growing);
		
			const float Duration = CropToGrow ?	CropToGrow->GrowTimeSeconds : GrowTimeSeconds;
		
			GetWorldTimerManager().SetTimer(
				GrowTimerHandle,
				this,
				&APlantPlot::FinishGrowing,
				Duration,
				false);
			break;
		}
	case EPlotState::Growing:
		break;

	case EPlotState::Ready:
		SetState(EPlotState::Empty);
		break;
	}
}

void APlantPlot::FinishGrowing()
{
	SetState(EPlotState::Ready);
}

void APlantPlot::SetState(EPlotState NewState)
{
	if (CurrentState == NewState) return;

	CurrentState = NewState;
	OnStateChanged(NewState);
}