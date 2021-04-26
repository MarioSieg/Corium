#include "../../Include/Nominax/Core/BasicReactorDescriptor.hpp"

namespace Nominax
{
	auto BasicReactorDescriptor::BuildDetailed() const noexcept -> DetailedReactorDescriptor
	{
		return
		{
			.SignalStatus = &this->SignalStatusFlag,
			.CodeChunk = this->CodeChunk.data(),
			.CodeChunkInstructionMap = this->CodeChunkInstructionMap.data(),
			.CodeChunkSize = this->CodeChunk.size(),
			.IntrinsicTable = this->IntrinsicTable.data(),
			.IntrinsicTableSize = this->IntrinsicTable.size(),
			.InterruptHandler = &this->InterruptHandler,
			.Stack = this->Stack.data(),
			.StackSize = this->Stack.size(),
		};
	}

	auto BasicReactorDescriptor::Validate() const noexcept -> ReactorValidationResult
	{
		return this->BuildDetailed().Validate();
	}
}