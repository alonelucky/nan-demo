const addon = require('../');
const assert = require('assert');
// console.log(addon)
addon.asyncAdd(1,2,(err,sum)=>{
    console.log(sum)
})

console.log(addon.syncAdd(0.1,"123"));

assert(
    addon.string 
    && typeof addon.string === 'string' 
    && addon.string === 'Hello my addon string',
    'String create faild');
assert(
    addon.number 
    && typeof addon.number === 'number' 
    && addon.number === 123,
    'number create faild');
assert(
    addon.bool 
    && typeof addon.bool === 'boolean' 
    && addon.bool === true,
    'bool create faild');