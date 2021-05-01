#pragma once

namespace Nominax
{
	/// <summary>
	/// Represents the style of a message box.
	/// </summary>
	enum class MessageBoxStyle
	{
		/// <summary>
		/// Info style.
		/// </summary>
		Info,

		/// <summary>
		/// Warning style.
		/// </summary>
		Warning,

		/// <summary>
		/// Error style.
		/// </summary>
		Error,

		/// <summary>
		/// Question style.
		/// </summary>
		Question
	};

	/// <summary>
	/// Type of buttons.
	/// </summary>
	enum class MessageBoxButtons
	{
		/// <summary>
		/// Ok button.
		/// </summary>
		Ok,

		/// <summary>
		/// Ok and cancel button.
		/// </summary>
		OkCancel,

		/// <summary>
		/// Yes and no button.
		/// </summary>
		YesNo
	};

	/// <summary>
	/// Return type of message box type.
	/// </summary>
	enum class MessageBoxSelection
	{
		/// <summary>
		/// Used pressed ok.
		/// </summary>
		Ok,

		/// <summary>
		/// Used pressed cancel.
		/// </summary>
		Cancel,

		/// <summary>
		/// Used pressed yes.
		/// </summary>
		Yes,

		/// <summary>
		/// Used pressed no.
		/// </summary>
		No,

		/// <summary>
		/// Used pressed none.
		/// </summary>
		None
	};
}