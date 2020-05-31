// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEditorWidget.h"
#include "EditorWidgetRow.h"
#include "EditorWidgetExampleSettings.h"
#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"

void UTestEditorWidget::AddChildWidget(UPanelWidget* PanelWidget)
{
    if (!PanelWidget)
    {
        return;
    }

    TSubclassOf<UEditorWidgetRow> EditorWidgetRowClass = GetDefault<UEditorWidgetExampleSettings>()->EditorWidgetRowClass;
    if (!EditorWidgetRowClass)
    {
        return;
    }

    UEditorWidgetRow* WidgetRow = CreateWidget<UEditorWidgetRow>(GetWorld(), EditorWidgetRowClass);
    if (IsValid(WidgetRow))
    {
        PanelWidget->AddChild(WidgetRow);
    }
}

void UTestEditorWidget::RemoveChildWidget(UPanelWidget* PanelWidget)
{
    if (!PanelWidget)
    {
        return;
    }

    const int32 ChildrenCount = PanelWidget->GetChildrenCount();

    if(ChildrenCount > 0)
    {
        PanelWidget->RemoveChildAt(ChildrenCount - 1);
    }
}
