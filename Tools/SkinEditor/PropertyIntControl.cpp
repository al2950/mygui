/*!
	@file
	@author		Albert Semenov
	@date		08/2010
*/
#include "precompiled.h"
#include "PropertyIntControl.h"

namespace tools
{

	PropertyIntControl::PropertyIntControl(MyGUI::Widget* _parent) :
		wraps::BaseLayout("PropertyEditControl.layout", _parent),
		mEdit(nullptr)
	{
		assignWidget(mEdit, "Edit");

		mEdit->eventEditTextChange += MyGUI::newDelegate(this, &PropertyIntControl::notifyEditTextChange);
	}

	PropertyIntControl::~PropertyIntControl()
	{
		mEdit->eventEditTextChange -= MyGUI::newDelegate(this, &PropertyIntControl::notifyEditTextChange);
	}

	void PropertyIntControl::updateProperty()
	{
		Property* prop = getProperty();
		if (prop != nullptr)
		{
			mEdit->setEnabled(true);
			mEdit->setCaption(prop->getValue());

			bool validate = isValidate();
			setColour(validate);
		}
		else
		{
			mEdit->setCaption("");
			mEdit->setEnabled(false);
		}
	}

	void PropertyIntControl::notifyEditTextChange(MyGUI::Edit* _sender)
	{
		Property* prop = getProperty();
		if (prop != nullptr)
		{
			bool validate = isValidate();
			if (validate)
				prop->setValue(getClearValue(), getTypeName());

			setColour(validate);
		}
	}

	bool PropertyIntControl::isValidate()
	{
		MyGUI::UString value = mEdit->getOnlyText();

		int value1 = 0;
		if (!MyGUI::utility::parseComplex(value, value1))
			return false;

		return true;
	}

	MyGUI::UString PropertyIntControl::getClearValue()
	{
		MyGUI::UString value = mEdit->getOnlyText();

		int value1 = 0;
		if (MyGUI::utility::parseComplex(value, value1))
			return MyGUI::utility::toString(value1);

		return "";
	}

	void PropertyIntControl::setColour(bool _validate)
	{
		MyGUI::UString value = mEdit->getOnlyText();
		if (!_validate)
			value = "#FF0000" + value;

		size_t index = mEdit->getTextCursor();
		mEdit->setCaption(value);
		mEdit->setTextCursor(index);
	}

} // namespace tools
