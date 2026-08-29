//Hannah Kellett D00260463
#include "udpPCH.hpp"
#include "command.hpp"

Command::Command() : action(), category(static_cast<unsigned int>(ReceiverCategories::kNone))
{
}
