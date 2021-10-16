package com.javaproject.ipldashboard.repository;

import com.javaproject.ipldashboard.model.Team;

import org.springframework.data.repository.CrudRepository;

public interface TeamRepository extends CrudRepository<Team, Long>{

    Team findByTeamName(String teamName);
    
}
