SELECT title
FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE name = "Johnny Depp"
and movie_id in(
    SELECT movie_id
    FROM people JOIN stars ON people.id = stars.person_id
    WHERE name = "Helena Bonham Carter"
);