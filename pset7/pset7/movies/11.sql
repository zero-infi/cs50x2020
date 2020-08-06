SELECT distinct(title)
FROM people JOIN stars ON people.id = stars.person_id
JOIN ratings ON ratings.movie_id = stars.movie_id
JOIN movies ON movies.id = stars.movie_id
WHERE people.name = "Chadwick Boseman" ORDER BY rating desc limit 5;