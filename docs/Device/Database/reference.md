# API Reference
!!! warning "Placeholder content"
	Content of this page is a placeholder and not final
## Base URL

``` php linenums="0"
http://localhost/api
```

## Endpoints
---
### POST
---
#### 1. Authenticate User

**Endpoint:** `/GetUser`  
**Method:** `POST`  
**Description:** Authenticates user based on an email and password.

**Request body:**
```json linenums="0"
{
  "email": "John.Doe@gmail.com",
  "password": "admin"
}
```

**Response:**

- **200 OK**
  ```json linenums="0"
  {
      "user_id": 1,
      "name": "John",
      "surname": "Doe"
  }
  ```

- **400 Bad Request**
```json linenums="0"
{
  "error": "Missing email or password"
}
```

- **401 Unauthorized**
```json linenums="0"
{
  "error": "Invalid email or password"
}
```