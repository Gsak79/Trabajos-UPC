using ExtraBonus.API.BonusCenter.Domain.Models;
using ExtraBonus.API.Shared.Domain.Services.Communication;

namespace ExtraBonus.API.BonusCenter.Domain.Services.Comunication;

public class BondResponse : BaseResponse<Bond>
{
    public BondResponse(string message) : base(message)
    {
    }

    public BondResponse(Bond resource) : base(resource)
    {
    } 
}