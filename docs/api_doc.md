# Edstem API Documentation

## Edapi

The project uses the open source API [edapi](https://github.com/smartspot2/edapi/tree/master). Due to some missing features required for the core objectives of the project to work we will be working with a forked version of the repository that has increased functionality.

The **original** API by [smartspot2](https://github.com/smartspot2) was intended to allow users to interact with edstem by obtaining basic course information and perform a variety of different actions with threads.

### Modifying the API

Initially the API was designed to only work with courses and threads however, we wanted to collect data from the course lessons so we had to make modifications to the repository.

### 1. Understanding the API

Let's quickly explain how the API works.

The way that the API is able to obtain data per user is by having the user obtain an authentication token through edstem and them storing their token in a `.env` file (which makes securing sensitive information more secure).

```env
ED_API_TOKEN=xxxxxx.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
```

Once we have this token we create an edstem object.
```python
ed = EdAPI()
```

With this edstem object we can now call a variety of functions from the edstem API.


### 2. Modification

During the early stages of development we only had access to perform functions with user_info and threads, not lessons and courses.

In order to start working on this we had to understand how the API works at an even deeper level.

#### Inspecting the Source Code

In order to understand what the API was doing so that we could modify/manipulate it we had to start playing around.

```python
@_ensure_login
def list_user_activity(
    self,
    /,
    user_id: int,
    course_id: int,
    *,
    limit: int = 30,
    offset: int = 0,
    filter: str = "all",
) -> list[API_ListUserActivity_Response_Item]:
    """
    Retrieve a list of comments and threads made by the user.

    Limit can range from 1 to 50 (anything higher will get clipped to 50).
    Offset can be used to list out all activity for a user iteratively,
    through pagination.

    GET /api/users/<user_id>/profile/activity?courseID=<course_id>
    """
    list_url = urljoin(API_BASE_URL, f"users/{user_id}/profile/activity")
    response = self.session.get(
        list_url,
        params={
            "courseID": course_id,
            "limit": limit,
            "offset": offset,
            "filter": filter,
        },
    )
    if response.ok:
        response_json: API_ListUserActivity_Response = response.json()
        return response_json.get("items", [])  # default to empty list

    _throw_error(
        f"Failed to list user activity for user {user_id} in course {course_id}.",
        response.content,
    )
```
>Code snippet from [edapi.py](https://github.com/smartspot2/edapi/blob/master/edapi/edapi.py)

The code snippet was the framework for all future implementations.

Let's break it down:
1. The function parameters specify what the url is going to contain.
2. Once the URL is created we need to check if we get a response with the new URL.
3. If it's valid then we create and return a json object containing all of the data, otherwise we throw an error.

>The function would return a specific datatype that was specified in `edapi/types/api_types/types` and `edapi/types/api_types/types/endpoints`.

#### Adding New Functions

The new functions that were added include:

* `get_lesson_content`: This function retrieved lesson content for a specific lesson.

* `get_challenge`: This function retrieved challenge data (grades, total points) from a lesson.

* `list_lessons`: This function retrieved all available lessons from a given course.

* `get_marking_status`: This function retrieved the marking status from a specific lesson which gives specific details from the most recent attempt of a lesson.

>For more details visit [Edapiwl](https://github.com/trevmoy/edapiwl/blob/main/edapi/edapi.py)

#### 4. Publishing the API

In order to check if users have the required API along with other packages we had to publish the modified API so that it is easily downloadable for users.

The API is listed on [PyPi](https://pypi.org/project/edapiwl/0.0.3/).

It can also be downloaded by running:
```
pip install edapiwl==0.0.3
```

### 3. Implementing Into Project

So, once we had all of these new functions working and collecting data we had to figure out how we were going to parse through our data in C++. 

To work around this we had decided to stick to something we had worked with consistently all year which was reading data from a text file.

So, while in Python we have the program create a `data.txt` file and we write all the information we would need to store in our data structures to the text file.

Now that our data is in the text file we are ready to [store it](dsa.md)!