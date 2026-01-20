#include "pane_panel.h"

#include "../../vendored/raygui.h"

void DVTPDrawPanel(DVTPDrawPanelParameters params) {
  BeginScissorMode(
    params.bounds.x, 
    params.bounds.y, 
    params.bounds.width,
                   
    params.bounds.height);

  ClearBackground(GetColor(
    GuiGetStyle(
      DEFAULT, 
      BACKGROUND_COLOR
  )));

  GuiGroupBox(
    (Rectangle){
      params.bounds.x, 
      params.bounds.y + params.padding,
      params.bounds.width,
      params.bounds.y - params.padding
    },
  "dvterrainproto"
  );

  EndScissorMode();

  EndDrawing();
}
