// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __C_GUI_MODAL_SCREEN_H_INCLUDED__
#define __C_GUI_MODAL_SCREEN_H_INCLUDED__

#include "IrrCompileConfig.h"
#ifdef _IRR_COMPILE_WITH_GUI_

#include "IGUIElement.h"

namespace irr
{
namespace gui
{

	class CGUIModalScreen : public IGUIElement
	{
	public:

		//! constructor
		CGUIModalScreen(IGUIEnvironment* environment, IGUIElement* parent, s32 id);

		//! called if an event happened.
		virtual bool OnEvent(const SEvent& event) _IRR_OVERRIDE_;

		//! Removes a child.
		virtual void removeChild(IGUIElement* child) _IRR_OVERRIDE_;

		//! Adds a child
		virtual void addChild(IGUIElement* child) _IRR_OVERRIDE_;


		//! draws the element and its children
		virtual void draw() _IRR_OVERRIDE_;

		//! Updates the absolute position.
		virtual void updateAbsolutePosition() _IRR_OVERRIDE_;

		//! Modalscreen is not a typical element, but rather acts like a state for it's children.
		//! isVisible is overriden to give this a useful behavior, so that a modal will no longer
		//! be active when its parent is invisible or all its children are invisible.
		virtual bool isVisible() const _IRR_OVERRIDE_;

		//! Modals are infinite so every point is inside
		virtual bool isPointInside(const core::position2d<s32>& point) const _IRR_OVERRIDE_;

		//! Writes attributes of the element.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) const _IRR_OVERRIDE_;

		//! Reads attributes of the element
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options) _IRR_OVERRIDE_;

		//! Set when to blink. 
		//! Bitset of following values (can be combined)
		//! 0 = never
		//! 1 = focus changes
		//! 2 = Left mouse button pressed down
		void setBlinkMode(u32 blink)
		{
			BlinkMode = blink;
		}

		u32 getBlinkMode() const
		{
			return BlinkMode;
		}

	protected:
		virtual bool canTakeFocus(IGUIElement* target) const;

	private:

		u32 BlinkMode;
		u32 MouseDownTime;
	};


} // end namespace gui
} // end namespace irr

#endif // _IRR_COMPILE_WITH_GUI_

#endif

