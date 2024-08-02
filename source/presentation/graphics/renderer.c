#include "renderer.h"
#include "../colour/theme.h"

static HBRUSH backgroundBrush;
static HBRUSH foregroundBrush;
static HBRUSH accentBrush;
static HPEN outlinePen;

void NeonInitRenderTools(void)
{
    backgroundBrush = CreateSolidBrush(NeonGetBackgroundColour());
    foregroundBrush = CreateSolidBrush(NeonGetForegroundColour());
    accentBrush = CreateSolidBrush(NeonGetAccentColour());
    outlinePen = CreatePen(PS_SOLID, 2, NeonGetForegroundColour());
}

HBRUSH NeonGetBackgroundBrush(void)
{
    return backgroundBrush;
}

HBRUSH NeonGetForegroundBrush(void)
{
    return foregroundBrush;
}

HBRUSH NeonGetAccentBrush(void)
{
    return accentBrush;
}

HPEN NeonGetOutlinePen(void)
{
    return outlinePen;
}

void NeonFreeRenderTools(void)
{
    (void) DeleteObject(backgroundBrush);
    (void) DeleteObject(foregroundBrush);
    (void) DeleteObject(accentBrush);
    (void) DeleteObject(outlinePen);
}