//
// Created by abdo on 7/6/25.
//

#include "../include/Member.h"
#include "../include/MemberManagment.h"

bool MemberManagement::addMember(const Member& member) {
    members.push_back(member);
    return true;
}

bool MemberManagement::removeMember(int id) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getId() == id) {
            members.erase(it);
            return true;
        }
    }
    return false;
}

bool MemberManagement::updateMember(int id, const std::string& name) {
    for (auto& member : members) {
        if (member.getId() == id) {
            member.setName(name);
            return true;
        }
    }
    return false;
}

std::optional<Member> MemberManagement::searchMember(int id) const {
    for (const auto& member : members) {
        if (member.getId() == id)
            return member;
    }
    return std::nullopt;
}

std::vector<Member> MemberManagement::getAllMembers() const {
    return members;
}
