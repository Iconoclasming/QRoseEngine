#version 330 core

uniform mat4 model;
uniform struct Light
{
	vec3 position;
	vec3 intensity;
} light;

in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;
  
out vec4 color;

void main()
{
	// Calculate normal matrix in world coordinates
	mat3 normalMatrix = transpose(inverse(mat3(model)));
	vec3 normal = normalize(normalMatrix * fragNormal);

	// Calculate the location of this fragment (pixel) in world coords
	vec3 fragPositionWorld = vec3((model * vec4(fragPosition, 1.0f)).xyz);

	// Calculate the vector from this pixels surface to the light source
	vec3 surfaceToLight = light.position - fragPositionWorld;

	// Calculate the cosine of the angle of incidence
	float brightness = dot(normal, surfaceToLight) / (length(surfaceToLight) * length(normal));
	brightness = clamp(brightness, 0.0f, 1.0f);

	// Calculate the final color of the pixel, based on:
	// 1. The angle of incidence: brightness
	// 2. The color/intensities of the light: light.intensities
	// 3. The color from vertex shader: fragColor (but should be a texture)
	color = vec4(brightness * light.intensity * fragColor.rgb, fragColor.a);
}