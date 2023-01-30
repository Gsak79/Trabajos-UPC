﻿using AutoMapper;
using ExtraBonus.API.BonusCenter.Domain.Models;
using ExtraBonus.API.BonusCenter.Domain.Services;
using ExtraBonus.API.BonusCenter.Resources;
using ExtraBonus.API.Shared.Extensions;
using Microsoft.AspNetCore.Mvc;

namespace ExtraBonus.API.BonusCenter.Controllers;



[ApiController]
[Route("/api/v1/[controller]")]
public class BondsController : ControllerBase
{
    private readonly IBondService _bondService;
    private readonly IMapper _mapper;

    public BondsController(IMapper mapper, IBondService bondService)
    {
        _mapper = mapper;
        _bondService = bondService;
    }
   
    [HttpGet]
    public async Task<IEnumerable<BondResource>> GetAllAsync()
    {
        var bonds = await _bondService.ListAsync();
        var resources = _mapper.Map<IEnumerable<Bond>, IEnumerable<BondResource>>(bonds);

        return resources;

    }
    
    [HttpGet("{id}")]
    public async Task<BondResource> GetByIdAsync(int id)
    {
        var bond = await _bondService.FindByIdAsync(id);
        var resource = _mapper.Map<Bond,BondResource>(bond);
        return resource;

    }
    
    
    [HttpPost]
    public async Task<IActionResult> PostAsync([FromBody] SaveBondResource resource)
    {
        if (!ModelState.IsValid)
            return BadRequest(ModelState.GetErrorMessages());

        var bond = _mapper.Map<SaveBondResource, Bond>(resource);

        var result = await _bondService.SaveAsync(bond);

        if (!result.Success)
            return BadRequest(result.Message);

        var bondResource = _mapper.Map<Bond, BondResource>(result.Resource);

        return Ok(bondResource);
    }
    
    [HttpPut("{id}")]
    public async Task<IActionResult> PutAsync(int id, [FromBody] SaveBondResource resource)
    {
        if (!ModelState.IsValid)
            return BadRequest(ModelState.GetErrorMessages());

        var bond= _mapper.Map<SaveBondResource, Bond>(resource);

        var result = await _bondService.UpdateAsync(id, bond);

        if (!result.Success)
            return BadRequest(result.Message);

        var bondResource = _mapper.Map<Bond, BondResource>(result.Resource);

        return Ok(bondResource);
    }

    [HttpDelete("{id}")]
    public async Task<IActionResult> DeleteAsync(int id)
    {
        var result = await _bondService.DeleteAsync(id);
        
        if (!result.Success)
            return BadRequest(result.Message);

        var bondResource = _mapper.Map<Bond, BondResource>(result.Resource);

        return Ok(bondResource);
    }
    
    
}