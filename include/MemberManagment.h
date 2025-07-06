//
// Created by abdo on 7/6/25.
//

#ifndef MEMBERMANAGEMENT_H
#define MEMBERMANAGEMENT_H

#include "Member.h"
#include <vector>
#include <optional>

class MemberManagement {
private:
    std::vector<Member> members;

public:
    bool addMember(const Member& member);
    bool removeMember(int id);
    bool updateMember(int id, const std::string& name);
    std::optional<Member> searchMember(int id) const;
    std::vector<Member> getAllMembers() const;
};

#endif
