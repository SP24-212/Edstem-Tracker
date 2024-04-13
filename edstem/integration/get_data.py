from edapi import EdAPI
from colorama import Fore
from datetime import datetime

# initialize Ed API
ed = EdAPI()
# authenticate user through the ED_API_TOKEN environment variable
ed.login()

# retrieve user information; authentication is persisted to next API calls
user_info = ed.get_user_info()

user = user_info['user']
print(f"Hello {user['name']}!")

# retrieve the list of courses
courses = user_info['courses']

# number of courses 
num_courses = len(courses)

# implement color later

# holds the course id
courses_with_lessons = []


# we will print the title and challenge id of all lessons with type cpp
with open("edstem/integration/edstem-data/data.txt", "w") as f:

  # we need to put the course data in then the lesson data
  # iterate through courses
  for i in range(num_courses):
    course = courses[i]
    # when there is a course with no lessons we will label it as such
    if 'lessons' not in course['course']['features']:
      f.write(f"st_course_id: '{course['course']['id']}'\n")
      f.write(f"st_code: '{course['course']['code']}'\n")
      f.write(f"st_name: '{course['course']['name']}'\n")
      f.write(f"st_lessons: 'False'\n")
    else:
      courses_with_lessons.append(course['course']['id'])
      f.write(f"st_course_id: '{course['course']['id']}'\n")
      f.write(f"st_code: '{course['course']['code']}'\n")
      f.write(f"st_name: '{course['course']['name']}'\n")
      f.write(f"st_lessons: 'True'\n")
  # we iterate through the lessons in the courses with lessons

  for k in range(len(courses_with_lessons)):

    ed_lesson = ed.list_lessons(courses_with_lessons[k])

    # we get the length of the lessons in the course k
    num_lessons = len(ed_lesson['lessons'])
    
    for i in range(num_lessons):
      if ed_lesson['lessons'][i]['type'] != 'general':
        

        if ed_lesson['lessons'][i]['openable'] == True:

          f.write(f"bhavl_course_id: '{courses_with_lessons[k]}'\n")
          f.write(f"bhavl_lesson_id: '{str(ed_lesson['lessons'][i]['id'])}'\n")
          try:
            f.write(f"bhavl_due_at: '{datetime.fromisoformat(ed_lesson['lessons'][i]['due_at']).strftime('%Y-%m-%d %H:%M:%S')}'\n")
          except:
            f.write(f"bhavl_due_at: 'Unavailable'\n")
          f.write(f"bhavl_type: '{ed_lesson['lessons'][i]['type']}'\n")
          f.write(f"bhavl_openable: '{ed_lesson['lessons'][i]['openable']}'\n")
          f.write(f"bhavl_title: '{ed_lesson['lessons'][i]['title']}'\n")
          f.write(f"bhavl_status: '{ed_lesson['lessons'][i]['status']}'\n")

          
          lesson_content = ed.get_lesson_content(ed_lesson['lessons'][i]['id'])

          # Try to get the attempt id
          try:
          
            attempt_id = lesson_content['lesson']['attempt_id'] # note the attempt id is the most recent attempt for the user. NOT THE BEST ATTEMPT.
            
            if attempt_id != 'null':
              try:
                marking_info = ed.get_marking_status(ed_lesson['lessons'][i]['id'], attempt_id)
              except:  
                continue
              else:
                possible_score = 0
                user_score = 0
                for j in range(len(marking_info['lesson_markable_marking_status'])):
                  possible_score += marking_info['lesson_markable_marking_status'][j]['total_points']
                user_score = marking_info['attempt_result']['mark']
                # print(marking_info['attempt_result']['completed_at'])
                f.write(f"bhavl_user_score: '{user_score}'\n")
                f.write(f"bhavl_potential_score: '{possible_score}'\n")
            else:
              continue
          except:
            continue

        # if the lesson is not openable we can't get the challenge id so we get the marking info
        else:
          f.write(f"bhavl_course_id: '{courses_with_lessons[k]}'\n")
          f.write(f"bhavl_lesson_id: '{str(ed_lesson['lessons'][i]['id'])}'\n")
          try:
            f.write(f"bhavl_due_at: '{datetime.fromisoformat(ed_lesson['lessons'][i]['due_at']).strftime('%Y-%m-%d %H:%M:%S')}'\n")
          except:
            f.write(f"bhavl_due_at: 'Unavailable'\n")
          f.write(f"bhavl_type: '{ed_lesson['lessons'][i]['type']}'\n")
          f.write(f"bhavl_openable: '{ed_lesson['lessons'][i]['openable']}'\n")
          f.write(f"bhavl_title: '{ed_lesson['lessons'][i]['title']}'\n")
          f.write(f"bhavl_status: '{ed_lesson['lessons'][i]['status']}'\n")


          
          lesson_content = ed.get_lesson_content(ed_lesson['lessons'][i]['id']) # get lesson content
          
          # get attempt id
          attempt_id = lesson_content['lesson']['attempt_id']

          # if trying to get marking info raises an error then we will not be able to get the user's score
          # we won't print anything about the user's score (for now)

          # try to get marking info
          try:
            marking_info = ed.get_marking_status(ed_lesson['lessons'][i]['id'], attempt_id)
          except:
            continue
          else:
            possible_score = 0
            user_score = 0
            for j in range(len(marking_info['lesson_markable_marking_status'])):
              possible_score += marking_info['lesson_markable_marking_status'][j]['total_points']
              user_score += marking_info['lesson_markable_marking_status'][j]['count_marked']
          # print the user's score and the total possible score
            f.write(f"bhavl_user_score: '{user_score}'\n")
            f.write(f"bhavl_potential_score: '{possible_score}'\n")

# tell user the data is now being stored and sorted
print(Fore.GREEN + "Data has been stored and sorted" + Fore.RESET)
