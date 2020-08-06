SELECT movies.title , ratings.rating
from movies
join ratings on id = movie_id
where year = 2010
order by ratings.rating desc , movies.title;