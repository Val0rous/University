package oop.lab03.acme;

public class Professor implements User {

	private final int id;
	private final String name;
	private final String surname;
	private final String password;
	private String[] courses;
	
	
	public Professor(final int id, final String name, 
			final String surname, final String password,
			String[] courses) {
		this.id = id;
		this.name = name;
		this.surname = surname;
		this.password = password;
		this.courses = courses;
	}
	
	public void replaceCourse(final String course, final int index) {
		this.courses[index] = course;
	}
	
	public void replaceAllCourses(final String[] courses) {
		this.courses = courses;
	}
	
	@Override
	public String getUsername() {
		return this.name;
	}

	@Override
	public String getPassword() {
		return this.password;
	}

	@Override
	public String getDescription() {
		return (this.name + " " + this.surname);
	}

}
