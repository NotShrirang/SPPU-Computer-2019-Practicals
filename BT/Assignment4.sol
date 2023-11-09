// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentRegistry {
    struct Student {
        string name;
        uint256 age;
    }

    Student[] private students;
    event ReceivedEther(address indexed sender, uint256 value);

    receive() external payable {
        emit ReceivedEther(msg.sender, msg.value);
    }

    fallback() external payable {
        emit ReceivedEther(msg.sender, msg.value);
    }

    function addStudent(string memory name, uint256 age) public {
        students.push(Student(name, age));
    }

    function getStudent(uint256 index) public view returns (string memory, uint256) {
        require(index < students.length, "Student not found...");
        return (students[index].name, students[index].age);
    }

    function getStudentCount() public view returns (uint256) {
        return students.length;
    }
}
