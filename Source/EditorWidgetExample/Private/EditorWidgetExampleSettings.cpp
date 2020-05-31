#include "EditorWidgetExampleSettings.h"
#include "UObject/ConstructorHelpers.h"
#include "TestEditorWidget.h"
#include "EditorWidgetRow.h"

UEditorWidgetExampleSettings::UEditorWidgetExampleSettings()
{
    static ConstructorHelpers::FClassFinder<UTestEditorWidget> TestEditorWidgetDefaultClass(
        TEXT("/EditorWidgetExample/TestEditorWidget/EW_Testwidget.EW_Testwidget_C"));

    if (TestEditorWidgetDefaultClass.Succeeded())
    {
        TestEditorWidgetClass = TestEditorWidgetDefaultClass.Class;
    }

    static ConstructorHelpers::FClassFinder<UEditorWidgetRow> EditorWidgetRowDefaultClass(
        TEXT("/EditorWidgetExample/TestEditorWidget/EW_EditorWidgetRow.EW_EditorWidgetRow_C"));
    if (EditorWidgetRowDefaultClass.Succeeded())
    {
        EditorWidgetRowClass = EditorWidgetRowDefaultClass.Class;
    }
}

