select distinct(name) from
people join stars on people.id = stars.person_id
where name != "Kevin Bacon" and movie_id IN (
    SELECT movie_id
    FROM people JOIN stars ON people.id = stars.person_id
    WHERE name = "Kevin Bacon" and birth = 1958
) ;