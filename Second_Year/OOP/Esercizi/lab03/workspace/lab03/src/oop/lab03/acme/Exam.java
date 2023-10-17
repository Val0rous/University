package oop.lab03.acme;

import java.util.Arrays;

public class Exam {
	private final int id;
	private final int maxStudents;
	private int registeredStudents;
	private final String courseName;
	private final Professor professor;
	private final ExamRoom room;
	private Student[] students;
	
	public Exam(final int id, final int maxStudents,
			final String courseName, final Professor professor, 
			final ExamRoom room) {
		this.id = id;
		this.maxStudents = maxStudents;
		this.registeredStudents = 0;
		this.courseName = courseName;
		this.professor = professor;
		this.room = room;
		this.students = new Student[this.maxStudents];
	}
	
	public int getId() {
		return this.id;
	}
	
	public int getMaxStudents() {
		return this.maxStudents;
	}
	
	public int getRegisteredStudents() {
		return this.registeredStudents;
	}
	
	public String getCourseName() {
		return this.courseName;
	}
	
	public Professor getProfessor() {
		return this.professor;
	}
	
	public ExamRoom getRoom() {
		return this.room;
	}
	
	public Student[] getStudentList() {
		return this.students;
	}
	
	public Student getStudent(final int index) {
		return this.students[index];
	}
	
	public void registerStudent(final Student student) {
		if(this.registeredStudents < this.maxStudents) {
			this.students[this.registeredStudents] = student;
			this.registeredStudents++;
		}
	}
	
	public String toString() {
		String temp = "Id: " + this.id + "\n"
				+ "Course: " + this.courseName
				+ "Professor: " + this.professor.getDescription() + "\n"
				+ "Exam Room: " + this.room.getDescription() + "\n"
				+ "Student count: " + this.registeredStudents + "/" + this.maxStudents + "\n"
				+ "List of Students: " + Arrays.toString(this.students) + "\n";
		return temp;
	}
}
