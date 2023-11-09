// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {

    mapping(address => uint256) private balances;

    function createAccount() public returns (address) {
        balances[msg.sender] = 0;
        return msg.sender;
    }

    function deposite(uint256 amount) public payable {
        balances[msg.sender] += amount;
    }

    function withdraw(uint256 amount) public payable {
        require(balances[msg.sender] >= amount, "Insufficient Funds");
        balances[msg.sender] -= amount;
    }
    
    function transfer(address recipient, uint256 amount) public {
        require(balances[msg.sender] >= amount, "Insufficient balance");
        balances[msg.sender] -= amount;
        balances[recipient] += amount;
    }

    function getBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}
