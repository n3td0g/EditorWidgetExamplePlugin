// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "TestEditorWidget.generated.h"

class UPanelWidget;

/**
 * 
 */
UCLASS()
class EDITORWIDGETEXAMPLE_API UTestEditorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void AddChildWidget(UPanelWidget* PanelWidget);
	
	UFUNCTION(BlueprintCallable)
	void RemoveChildWidget(UPanelWidget* PanelWidget);
};
