# Edstem API Documentation

## edapi

The project uses the open source API [edapi](https://github.com/smartspot2/edapi/tree/master). Due to some missing features required for the core objectives of the project to work we will be working with a forked version of the repository that has increased functionality.

The **original** API by [smartspot2](https://github.com/smartspot2) was intended to allow users to interact with edstem by obtaining basic course information and perform a variety of different actions with threads.

### Modifying the API

Initially the API was designed to only work with courses and threads however, we wanted to collect data from the course lessons so we had to make modifications to the repository.

### 1. Understanding the API

The way that the API is able to obtain data per user is by having the user obtain an authentication token through edstem and them storing their token in a `.env` file (which makes securing sensitive information more secure).

```env
ED_API_TOKEN=xxxxxx.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
```

Once we have this token we create an edstem object.
```python
ed = EdAPI()
```

with this edstem object we can now call a variety of functions from