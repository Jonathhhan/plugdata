/*
 // Copyright (c) 2021-2022 Timothy Schoen
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#pragma once

#include "StackShadow.h"
#include "../Constants.h"

class CheckedTooltip : public TooltipWindow {

public:
    CheckedTooltip(Component* target, std::function<bool(Component*)> checkTooltip, int timeout = 500)
        : TooltipWindow(target, timeout)
        , tooltipShadow(DropShadow(Colour(0, 0, 0).withAlpha(0.2f), 4, { 0, 0 }), Corners::defaultCornerRadius)
        , checker(checkTooltip)
    {
        setOpaque(false);
        tooltipShadow.setOwner(this);
    }

    void hide(bool hidden)
    {
        // TooltipWindow already uses the setVisible flag internally, we can't use that, so we use setAlpha instead
        // setAlpha(!hidden);
        // tooltipShadow.setOwner(hidden ? nullptr : this);
    }

private:
    String getTipFor(Component& c) override
    {
        if (checker(&c)) {
            return TooltipWindow::getTipFor(c);
        } else {
            return "";
        }
    }

    std::function<bool(Component*)> checker;
    StackDropShadower tooltipShadow;
};
